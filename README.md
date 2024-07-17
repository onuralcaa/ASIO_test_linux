# Asio Library

[![Build Status](https://travis-ci.org/yourusername/asio.svg?branch=main)](https://travis-ci.org/yourusername/asio)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

Asio, C++ programlama dilinde asenkron girdi/çıktı operasyonlarını kolaylaştırmak için kullanılan, çok platformlu bir kütüphanedir. Bu kütüphane, ağ programlaması ve diğer düşük seviyeli I/O işlemleri için yaygın olarak kullanılır.

## Özellikler

- Asenkron TCP ve UDP
- Zamanlayıcılar
- Seri port iletişimi
- Sinyal işlemleri
- Çoklu iş parçacığı desteği

## Kurulum

### Ön Koşullar

Asio'yu kullanabilmek için aşağıdaki gereksinimlere sahip olmanız gerekmektedir:

- C++11 veya daha üstü bir standart destekleyen bir C++ derleyicisi
- Boost kütüphanesi (Opsiyonel, bazı Asio özellikleri Boost kütüphanesine bağımlı olabilir)

### Derleme ve Kurulum

#### Standalone Asio

Asio'yu bağımsız bir kütüphane olarak kullanmak için aşağıdaki adımları izleyebilirsiniz:

1. Asio'yu GitHub reposundan klonlayın:

    ```bash
    git clone https://github.com/chriskohlhoff/asio.git
    cd asio
    ```

2. Projenize Asio kütüphanesini dahil edin. Örneğin, CMake kullanıyorsanız:

    ```cmake
    cmake_minimum_required(VERSION 3.10)
    project(MyProject)

    set(CMAKE_CXX_STANDARD 11)

    include_directories(/path/to/asio/include)

    add_executable(MyProject main.cpp)
    ```

#### Boost Asio

Asio, Boost kütüphanesinin bir parçası olarak da kullanılabilir. Bunun için Boost kütüphanesini indirip kurmanız yeterlidir:

1. Boost'u indirip kurun:

    ```bash
    sudo apt-get install libboost-all-dev
    ```

2. Projenize Boost.Asio'yu dahil edin. Örneğin, CMake kullanıyorsanız:

    ```cmake
    cmake_minimum_required(VERSION 3.10)
    project(MyProject)

    set(CMAKE_CXX_STANDARD 11)

    find_package(Boost REQUIRED COMPONENTS system)
    include_directories(${Boost_INCLUDE_DIRS})

    add_executable(MyProject main.cpp)
    target_link_libraries(MyProject ${Boost_LIBRARIES})
    ```

## Kullanım

Basit bir TCP sunucusu örneği:

```cpp
#include <iostream>
#include <asio.hpp>

using asio::ip::tcp;

int main() {
    try {
        asio::io_context io_context;
        tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), 12345));

        while (true) {
            tcp::socket socket(io_context);
            acceptor.accept(socket);

            std::string message = "Hello from Asio!";
            asio::write(socket, asio::buffer(message));
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
