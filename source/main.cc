#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <cmath>

const int width = 182;
const int height = 47;

// const int width = 640;
// const int height = 144;

const int symbolWidth = 14;
const int symbolHeight = 35;

int main() {
    char buffer[width * height];
    std::string gradient = " .:!r1/(l4Z9HW8$@";

    unsigned long long frame = 0;
    while (true) {
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                float x = ((float)j / width - 0.5f) * 2.0f;
                float y = ((float)i / height - 0.5f) * 2.0f;
                float prop = (float)width / height;
                float symbolProp = (float)symbolWidth / symbolHeight;
                x *= prop * symbolProp;

                x += sin(frame / 10.0f);

                int index = int(sqrt(x * x + y * y) / 1.7f * (gradient.size() + 10));
                index = index >= gradient.size() ? gradient.size() - 1 : index;
                index = gradient.size() - index - 1;
                buffer[i * width + j] = gradient[index];
            }
            buffer[(i + 1) * width] = '\n';
        }

        std::cout << buffer;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        frame++;
    }

    return 0;
}
