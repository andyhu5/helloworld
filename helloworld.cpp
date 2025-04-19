#include <fmt/core.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <ranges>
#include <iostream>


int main()
{
    fmt::print("Hello World!\n");

    // use spdlog to log a message
    spdlog::info("Hello, {}!", "world");
    spdlog::error("An error occurred: {}", "some error message");
    spdlog::warn("Warning: {}", "this is a warning");
    spdlog::debug("Debug message: {}", "this is a debug message");
    spdlog::critical("Critical error: {}", "this is a critical error");
    spdlog::trace("Trace message: {}", "this is a trace message");
    spdlog::set_level(spdlog::level::debug); // Set global log level to debug

    auto even = [](int i) { return 0 == i % 2; };
    auto square = [](int i) { return i * i; };

    for (int i : std::views::iota(0, 10)
        | std::views::filter(even)
        | std::views::transform(square))
        std::cout << i << ' ';
    std::cout << '\n';

    return 0;
}