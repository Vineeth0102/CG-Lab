import cv2
import matplotlib.pyplot as plt

# Read the image
image = cv2.imread('image.png')
if image is None:
    print("Error: Could not read the image.")
    exit()

# Blurring and smoothing techniques
# 1. Averaging
blur_avg = cv2.blur(image, (5, 5))

# 2. Gaussian Blurring
blur_gaussian = cv2.GaussianBlur(image, (5, 5), 0)

# 3. Median Blurring
blur_median = cv2.medianBlur(image, 5)

# 4. Bilateral Filtering
blur_bilateral = cv2.bilateralFilter(image, 9, 75, 75)

# Display images using Matplotlib
titles = ['Original', 'Averaging', 'Gaussian Blurring', 'Median Blurring', 'Bilateral Filtering']
images = [image, blur_avg, blur_gaussian, blur_median, blur_bilateral]

plt.figure(figsize=(15, 10))
for i, (img, title) in enumerate(zip(images, titles)):
    plt.subplot(2, 3, i + 1)
    plt.imshow(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))
    plt.title(f'{title} (by 4MT21CS156)')
    plt.axis('off')

plt.tight_layout()
plt.show()
