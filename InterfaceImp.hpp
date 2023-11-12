// Interface_impl.hpp

#pragma once


template <typename... Args>
void Interface::lerValores(const Args&... args) {
    lerValoresImpl(args...);
}

template <typename T, typename... Rest>
void Interface::lerValoresImpl(const std::string& nome, T& valor, Rest&... restantes) {
    std::cout << "Digite o " << nome << ": ";
    std::cin >>  std::forward<T>valor;

    lerValoresImpl(restantes...);
}

// Caso base para encerrar a recursão variádica
inline void Interface::lerValoresImpl() {}

template <typename... Args>
    static void lerValores(const Args&... args); 

private:
    template <typename T, typename... Rest>
    static void lerValoresImpl(const std::string& nome, T& valor, Rest&... restantes);

    // Caso base para encerrar a recursão variádica
    static void lerValoresImpl(); 