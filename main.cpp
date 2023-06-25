#include "Parse.hpp"
#include "Lexer.hpp"


#define PATH "src/levels/level-1.dat"

int main(int argc, char *argv[]) 
{
    std::string file_name;

    if(argc > 1) {
        file_name = argv[1];
    } else {
        file_name = PATH;
    }

    Lexer lexer(file_name);
    auto Lines_blocks = lexer.tokenize_file();

    Parse parse;
    parse.parse(Lines_blocks);

    return 0;
}
// #include <SFML/Graphics.hpp>
// #include <SFML/Window/Joystick.hpp>
// #include <iostream>
// #include <map>
// #include <string>

// std::string ps4ButtonToString(int button) {
//     static const std::map<int, std::string> buttonToStringMap = {
//         { 0, "X" },
//         { 1, "CIRCLE" },
//         { 2, "TRIANGLE" },
//         { 3, "SQUARE" },
//         { 4, "L1" },
//         { 5, "R1" },
//         { 6, "L2" },
//         { 7, "R2" },
//         { 8, "Share" },
//         { 9, "Options" },
//         { 10, "PS" },
//         { 11, "L3" },
//         { 12, "R3" }
//         // { 13, "PadUp" },
//         // { 14, "PadDown" },
//         // { 15, "PadLeft" },
//         // { 16, "PadRight" }
//     };

//     auto it = buttonToStringMap.find(button);
//     if (it != buttonToStringMap.end()) {
//         return it->second;
//     } else {
//         return "Unknown";
//     }
// }

// std::string xboxButtonToString(int button) {
//     static const std::map<int, std::string> buttonToStringMap = {
//         { 0, "A" },
//         { 1, "B" },
//         { 2, "X" },
//         { 3, "Y" },
//         { 4, "L1" },
//         { 5, "R1" },
//         { 6, "Share" },
//         { 7, "Options" },
//         { 8, "X-Box" },
//         { 9, "L3" },
//         { 10, "R3" }
//     };

//     auto it = buttonToStringMap.find(button);
//     if (it != buttonToStringMap.end()) {
//         return it->second;
//     } else {
//         return "Unknown";
//     }
// }

// #include <SFML/Graphics.hpp>
// #include <SFML/Window/Joystick.hpp>
// #include <iostream>
// #include <map>
// #include <string>




// #include <SFML/Graphics.hpp>
// #include <SFML/Window/Joystick.hpp>
// #include <iostream>

// int main() {
//     sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Game");

    
//     while (window.isOpen()) {
//         sf::Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == sf::Event::Closed) {
//                 window.close();
//             }

//             sf::Joystick::Identification id_1 = sf::Joystick::getIdentification(0);
//             std::cout << id_1.name.toAnsiString() << "\n";
//             if (sf::Joystick::isConnected(0)) {
//                 if (event.type == sf::Event::JoystickButtonPressed) {
//                     if(sf::Joystick::isButtonPressed(0,1)){//"Circle" button on the ps4 controller
//                         window.close();
//                         return 0;
//                     }
//                     // Set the PS4 controller as the active gamepad
//                     sf::Joystick::Identification id_1 = sf::Joystick::getIdentification(0);
//                     if (id_1.name == "Sony Interactive Entertainment Wireless Controller" || "Sony Computer Entertainment Wireless Controller") {
//                         for (size_t i = 0; i < sf::Joystick::getButtonCount(0); ++i) {
//                             if (sf::Joystick::isButtonPressed(0, i)) {
//                                 std::string buttonName = ps4ButtonToString(i);
//                                 std::cout << "Ps4 Button pressed: " << buttonName << std::endl;
//                             }
//                         }
//                     }
//                     sf::Joystick::Identification id_2 = sf::Joystick::getIdentification(0);
//                     // std::cout << id_2.name.toAnsiString() << "\n";
//                     if (id_2.name == "Microsoft X-Box One S pad") {
//                         for (size_t i = 0; i < sf::Joystick::getButtonCount(0); ++i) {
//                             if (sf::Joystick::isButtonPressed(0, i)) {
//                                 std::string buttonName = xboxButtonToString(i);
//                                 std::cout << "X-Box Button pressed: " << buttonName << std::endl;
//                             }
//                         }
//                     }
//                     // sf::Joystick::hasAxis(0, sf::Joystick::);
                        
//                 } 
//                 // else {
//                 //     std::cout << "PS4 controller not found." << "\n";
//                 // }
                    
                
                
//             } else {
//                 std::cout << "No gamepad connected." << std::endl;
//             }
//         }

       
//         window.clear();

        
//         window.display();
//     }

//     return 0;
// }
// #include <iostream>
// #include <SFML/Graphics.hpp>

// int main(void)
// {
//     sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Joystick Use", sf::Style::Default);
//     sf::Event e;

//     sf::RectangleShape square;
//     square.setFillColor(sf::Color(255, 0, 0, 255));
//     square.setPosition(window.getSize().x / 2, window.getSize().y / 2);
//     square.setOutlineColor(sf::Color(0, 0, 0, 255));
//     square.setSize(sf::Vector2f(50.f, 50.f));
//     //get information about the joystick
//     sf::Joystick::Identification id = sf::Joystick::getIdentification(0);
//     std::cout << "\nVendor ID: " << id.vendorId << "\nProduct ID: " << id.productId << std::endl;
//     sf::String controller("Joystick Use: " + id.name);
//     window.setTitle(controller);//easily tells us what controller is connected
//     //query joystick for settings if it's plugged in...
//     if (sf::Joystick::isConnected(0)){
//         // check how many buttons joystick number 0 has
//         unsigned int buttonCount = sf::Joystick::getButtonCount(0);

//         // check if joystick number 0 has a Z axis
//         bool hasZ = sf::Joystick::hasAxis(0, sf::Joystick::Z);

//         std::cout << "Button count: " << buttonCount << std::endl;
//         std::cout << "Has a z-axis: " << hasZ << std::endl;
//     }
//     bool move = false;//indicate whether motion is detected
//     int turbo = 1;//indicate whether player is using button for turbo speed ;)

//     //for movement
//     sf::Vector2f speed = sf::Vector2f(0.f,0.f);

//     //time
//     sf::Clock tickClock;
//     sf::Time timeSinceLastUpdate = sf::Time::Zero;
//     sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
//     sf::Time duration = sf::Time::Zero;
//     bool running = true;
//     while (running){
//         while (window.pollEvent(e)){
//             if (e.type == sf::Event::KeyPressed){
//                 switch (e.key.code){
//                 case sf::Keyboard::Escape:
//                 {
//                     window.close();
//                     return 0;
//                 }
//                     break;
//                 default:
//                     break;
//                 }
//             }

//             if (e.type == sf::Event::JoystickMoved){
//                 move = true;
//                 std::cout << "X axis: " << speed.x << std::endl;
//                 std::cout << "Y axis: " << speed.y << std::endl;
//             }
//             else{
//                 move = false;
//             }

//             if (sf::Joystick::isButtonPressed(0, 0)){//"A" button on the XBox 360 controller
//                 turbo = 2;
//             }

//             if (!sf::Joystick::isButtonPressed(0, 0)){
//                 turbo = 1;
//             }

//             if(sf::Joystick::isButtonPressed(0,1)){//"B" button on the XBox 360 controller
//                 window.close();
//                 return 0;
//             }
//         }
//         //check state of joystick
//         speed = sf::Vector2f(sf::Joystick::getAxisPosition(0, sf::Joystick::X), sf::Joystick::getAxisPosition(0, sf::Joystick::Y));

//         timeSinceLastUpdate += tickClock.restart();
//         while (timeSinceLastUpdate > TimePerFrame)
//         {
//             timeSinceLastUpdate -= TimePerFrame;
//             if (speed.x > 15.f || speed.x < -15.f || speed.y > 15.f || speed.y < -15.f)
//                 square.move(turbo*speed.x*TimePerFrame.asSeconds(), turbo*speed.y*TimePerFrame.asSeconds());
//         }

//         window.clear(sf::Color(255, 0, 255));
//         window.draw(square);
//         window.display();
//     }
//     return 0;
// }

