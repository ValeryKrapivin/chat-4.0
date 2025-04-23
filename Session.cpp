void Session::handle_request(const std::string& request) {
     // Пример обработки запроса: регистрация или авторизация
     
     // Пример регистрации пользователя
     if (request.substr(0 ,9 ) == "REGISTER ") { 
         auto parts = split(request.substr(9), ' ');
         if(parts.size() == 2 && db_.register_user(parts[0], parts[1])) {
             logger_.log("User registered: " + parts[0]); // Логируем регистрацию
             do_write("Registration successful\n");
         } else {
             do_write("Registration failed\n");
         }
     }
     
     // Пример авторизации пользователя
     else if(request.substr(0 ,8 ) == "LOGIN ") { 
         auto parts = split(request.substr(8), ' ');
         if(parts.size() == 2 && db_.authenticate_user(parts[0], parts[1])) {
             logger_.log("User logged in: " + parts[0]); // Логируем авторизацию
             do_write("Login successful\n");
         } else {
             do_write("Login failed\n");
         }
     }
     
     // Пример отправки сообщения
     else if(request.substr(0 ,7 ) == "MESSAGE ") { 
         auto parts = split(request.substr(7), ' ');
         if(parts.size() >= 2){
             save_message(parts[0], parts[1], request.substr(7 + parts[0].length() + parts[1].length() + 2));
             logger_.log("Message from " + parts[0] + " to " + parts[1] + ": " + request.substr(7 + parts[0].length() + parts[1].length() + 2)); // Логируем сообщение
             do_write("Message sent\n");
         } else{
             do_write("Invalid message format\n");
         }
     }
}
