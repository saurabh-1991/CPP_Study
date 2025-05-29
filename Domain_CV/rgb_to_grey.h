#pragma once

#include<vector>
#include<iostream>

struct RGB {
	uint8_t r, g, b;
};

// Define a function to convert RGB to grayscale

uint8_t rgbToGreyscale(const RGB& img) {
	// Use the luminosity method to convert to grayscale
	return static_cast<uint8_t>(0.21 * img.r + 0.72 * img.g + 0.07 * img.b);
}

// Define a function to convert a color image to grayscale

std::vector<std::vector<uint8_t>> convertToGrayscale(const std::vector<std::vector<RGB>>& ColorImg) {
	// Get the dimensions of the image
	size_t height = ColorImg.size();
	size_t width = ColorImg[0].size();
	// Create a 2D vector to hold the grayscale image
	std::vector<std::vector<uint8_t>> grayscaleImage(height,std::vector<uint8_t>(width));
	// Convert each pixel to grayscale
	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; j < width; j++) {
			grayscaleImage[i][j] = rgbToGreyscale(ColorImg[i][j]);
		}
	}
	return grayscaleImage;
}