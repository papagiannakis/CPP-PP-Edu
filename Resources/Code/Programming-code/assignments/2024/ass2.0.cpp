#include <iostream>
#include <fstream>
#include <cmath>

// Function to write the PPM header
void write_ppm_header(std::ofstream &file, int width, int height) {
    file << "P3\n" << width << ' ' << height << "\n255\n";
}

// Function to generate and write the wave pattern
void generate_wave_pattern(std::ofstream &file, int width, int height);

void generate_wave_pattern(std::ofstream &file, int width, int height) {
    const double frequency = 0.5; // Frequency of the sine wave

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            double value = (std::sin(x * frequency) + 1) / 2; // Normalized sine wave value
            int red = static_cast<int>(value * 255);
            int green = static_cast<int>((1 - value) * 255);
            int blue = 128; // Constant blue value for color variation

            file << red << ' ' << green << ' ' << blue << "\t";
        }
        file << '\n';
    }
}

int main() {
    const int image_width = 400;
    const int image_height = 400;
    std::ofstream ppm_file("wave_pattern.ppm");

    if (!ppm_file) {
        std::cerr << "Error: Could not open the file for writing.\n";
        return 1;
    }

    write_ppm_header(ppm_file, image_width, image_height);
    generate_wave_pattern(ppm_file, image_width, image_height);

    ppm_file.close();
    std::cout << "Wave pattern image generated as 'wave_pattern.ppm'\n";
    return 0;
}