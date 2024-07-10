import cv2
import numpy as np
import matplotlib.pyplot as plt

# Read the image
image = cv2.imread('image.png')
if image is None:
    print("Error: Could not read the image.")
    exit()

# Convert the image to grayscale
gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Edge detection using Sobel filter
sobel_x = cv2.Sobel(gray_image, cv2.CV_64F, 1, 0, ksize=5)
sobel_y = cv2.Sobel(gray_image, cv2.CV_64F, 0, 1, ksize=5)
sobel_combined = cv2.sqrt(cv2.addWeighted(cv2.pow(sobel_x, 2.0), 1.0, cv2.pow(sobel_y, 2.0), 1.0, 0.0))

# Edge detection using Laplacian filter
laplacian = cv2.Laplacian(gray_image, cv2.CV_64F)

# Texture detection using Gabor filter
gabor_kernel = cv2.getGaborKernel((21, 21), 5.0, np.pi / 4, 10.0, 0.5, 0, ktype=cv2.CV_32F)
gabor = cv2.filter2D(gray_image, cv2.CV_8UC3, gabor_kernel)

# Display images using Matplotlib
titles = ['Original', 'Sobel Edge Detection', 'Laplacian Edge Detection', 'Gabor Texture Detection']
images = [gray_image, sobel_combined, laplacian, gabor]

plt.figure(figsize=(12, 12))
for i, (img, title) in enumerate(zip(images, titles)):
    plt.subplot(2, 2, i + 1)
    if title == 'Original':
        plt.imshow(img, cmap='gray')
    else:
        plt.imshow(np.abs(img), cmap='gray')
    plt.title(f'{title} (by 4MT21CS181)')
    plt.axis('off')

plt.tight_layout()
plt.show()
