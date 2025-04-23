#include "Logger.hpp" // Добавьте этот include

class Session : public std::enable_shared_from_this<Session> {
public:
    Session(tcp::socket socket);

    void start();

private:
    void do_read();
    
private:
     void handle_request(const std::string& request);
     void do_write(const std::string& response);

private:
     tcp::socket socket_;
     char data_[1024];
     Database db_{"chat.db"};
     Logger logger_{"log.txt"}; // Добавьте объект логгера
};
