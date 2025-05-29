#pragma once
#include<vector>
#include<iostream>

// Function to perform 2D convolution

// Define the 2D vector type for the image
using Image = std::vector<std::vector<float>>;

Image convolution2D(Image& InputImage, Image& kernel) {
	size_t height = InputImage.size();
	size_t width = InputImage[0].size();
	size_t kernelHeight = kernel.size();
	size_t kernelWidth = kernel[0].size();
	// Calculate the padding size
	size_t padheight = kernelHeight / 2;
	size_t padwidth = kernelWidth / 2;
	// Create Placeholder for Padded Image
	Image PaddedImage(height + 2 * padheight, std::vector<float>(width + 2 * padwidth,0.0));
	// Create Placeholder for Output Image
	Image OutputImage(height , std::vector<float>(width , 0.0));

	// Copy the original image into the padded image
	for (size_t i = 0; i < height; ++i) {
		for (size_t j = 0; j < width; ++j) {
			PaddedImage[i + padheight][j + padwidth] = InputImage[i][j];
		}
	}
	//Perform Convolution
	for (size_t img_r = padheight; img_r < height + padheight; ++img_r) {
		for (size_t img_c = padwidth; img_c < width + padwidth; ++img_c) {
			float sum = 0.0;
			for (size_t filter_r = 0; filter_r < kernelHeight; ++filter_r) {
				for (size_t filter_c = 0; filter_c < kernelWidth; ++filter_c) {
					sum += PaddedImage[img_r - padheight + filter_r][img_c - padwidth + filter_c] * kernel[filter_r][filter_c];

				}
			}
			OutputImage[img_r - padheight][img_c - padwidth] = sum;

		}
	}
	return OutputImage;
}