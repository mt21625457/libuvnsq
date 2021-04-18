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

