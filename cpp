#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Load the cascade
    cv::CascadeClassifier face_cascade;
    if (!face_cascade.load("haarcascade_frontalface_default.xml")) {
        std::cout << "Error loading face cascade file." << std::endl;
        return -1;
    }

    // Read the image file
    cv::Mat image = cv::imread("test_image.jpg");
    if (image.empty()) {
        std::cout << "Could not read the image." << std::endl;
        return -1;
    }

    // Convert to grayscale
    cv::Mat gray;
    cvtColor(image, gray, cv::COLOR_BGR2GRAY);

    // Detect faces
    std::vector<cv::Rect> faces;
    face_cascade.detectMultiScale(gray, faces);

    // Draw rectangles around the faces
    for (size_t i = 0; i < faces.size(); i++) {
        cv::rectangle(image, faces[i], cv::Scalar(255, 0, 0), 2);
    }

    // Show the output
    cv::imshow("Face Detection", image);
    cv::waitKey(0);

    return 0;
}
