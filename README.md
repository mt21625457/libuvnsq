# uvnsq
Async C++ client library for [NSQ][1]

This project has done the compiler optimization to the original project UVNSQ, has added the example

## BUILD

```
#linux or mac
./build.sh

#windows
Not yet realized

#example
mkdir build 
cd build 
cmake .. && make -j4
```



## Example

### PUB:

```
#include <iostream>

#include <unistd.h>
#include <thread>

#include <uvnsq/NsqProducer.h>


int main()
{
    uv::LogWriter::Instance()->setLevel(uv::LogWriter::Warn);

    uv::EventLoop loop;
    uv::SocketAddr addr("127.0.0.1",4150);

    nsq::NsqProducer npub(&loop,addr);
    std::string topic = "123456";
    std::string bady= "hello nsq";

   
    while(1) {
        npub.pub(topic,bady);
        std::cout << "pub: " << bady << std::endl;
        loop.runNoWait();
        uv_sleep(1000);
    }
     
    return 0;
}


```



### SUB:

```
#include <iostream>
#include <uvnsq/NsqConsumer.h>


int main()
{
    uv::LogWriter::Instance()->setLevel(uv::LogWriter::Warn);

    uv::EventLoop loop;
    std::string topic = "123456";
    std::string channal = "ch1";

    nsq::NsqConsumer nsub(&loop,topic,channal);
    uv::SocketAddr addr("127.0.0.1",4150);
  
    nsub.setNsqd(addr);

    std::function<void(std::string&)> fun = [](std::string & msg){
        std::cout << "response msg: " << msg <<std::endl;
    };
    nsub.setOnNsqResp(fun);

    std::function<void(nsq::NsqMessage&)> funm = [](nsq::NsqMessage&msg){
        std::cout << "sub: " << msg.MsgBody() <<std::endl;
    };
    nsub.setOnNsqMessage(funm);

    nsub.sub(topic,channal);
    nsub.start();


    while(1)
    {
        int num = loop.runNoWait();
        if(num > 0) {
            uv_sleep(1000);
            //std::cout << " runNoWait ....num: "<< num <<std::endl;
        }else {
            uv_sleep(1000);
            //std::cout << " runNoWait ....num: "<< num <<std::endl;
        }
    }

    return 0;
}
```



[1]: https://github.com/nsqio/nsq
[2]: https://github.com/wlgq2/uv-cpp
[3]: https://github.com/nlohmann/json
