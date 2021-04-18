
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