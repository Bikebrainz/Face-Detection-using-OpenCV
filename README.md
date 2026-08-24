# Face-Detection-using-OpenCV

Detects faces in an image with OpenCV's Haar cascade classifier and draws a blue
rectangle around each one.

Learning-exercise code from 2023 — one file, OpenCV only.

---

## ⚠️ The committed source is the wrong file

`cpp` currently contains a **linear-regression program**, not face detection —
the same code as
[Basic-Machine-Learning-Algorithm---Linear-Regression](https://github.com/Bikebrainz/Basic-Machine-Learning-Algorithm---Linear-Regression).
It was pasted over the real source by commit
[`528477a`](https://github.com/Bikebrainz/Face-Detection-using-OpenCV/commit/528477a)
("Update cpp") on 2023-11-11, about six minutes after the correct file landed.

Nothing was lost — the original is still in history at
[`34ddf6b`](https://github.com/Bikebrainz/Face-Detection-using-OpenCV/commit/34ddf6b).
To restore it:

```bash
git checkout 34ddf6b -- cpp
git commit -m "Restore face-detection source overwritten in 528477a"
```

Everything below describes that restored program.

---

## What it does

1. Loads `haarcascade_frontalface_default.xml` into a `cv::CascadeClassifier`
2. Reads `test_image.jpg` from the working directory
3. Converts it to grayscale — the cascade works on intensity, not color
4. Runs `detectMultiScale` to get a `std::vector<cv::Rect>` of faces
5. Draws a blue 2px rectangle over each hit
6. Shows the result in a window and waits for a keypress

A missing cascade file or unreadable image prints a message and exits `-1`.

## Requirements

- **OpenCV** (4.x). `brew install opencv`, `apt install libopencv-dev`, or vcpkg.
- **`haarcascade_frontalface_default.xml`** in the working directory. It ships
  with OpenCV under `data/haarcascades/`, or download it from the
  [OpenCV repo](https://github.com/opencv/opencv/tree/master/data/haarcascades).
- **`test_image.jpg`** — your input image, same directory.

Both paths are relative and hardcoded, so run the binary from the folder holding
those two files.

## Build and run

The source file is named `cpp` with **no extension** — pass it to the compiler
explicitly, or rename it to `main.cpp` first.

```bash
g++ -x c++ -o face-detect cpp $(pkg-config --cflags --libs opencv4)
./face-detect
```

`cv::imshow` needs a display, so this won't work over a plain SSH session or in
a headless container — swap in `cv::imwrite("out.jpg", image)` there.

## Known limits

Haar cascades are from 2001 and it shows: they want frontal, upright,
well-lit faces, and they produce false positives on busy backgrounds.
`detectMultiScale` is called with defaults, so there is no `minNeighbors` or
`minSize` tuning to trade sensitivity against noise. For anything real, OpenCV's
DNN face detector or a modern model will be far more accurate.
