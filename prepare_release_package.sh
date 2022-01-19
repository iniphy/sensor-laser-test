#!/bin/sh
rm sensor-laser-test_release.zip
mkdir release_package
# Copy sensor-laser-test binary
cp bin/sensor-laser-test.exe release_package/
# Copy RecFusion files (change this path if different!)
cp "C:/Program Files/ImFusion/RecFusionSDK 1.3.6/bin/." release_package/ -r
rm release_package/LicenseTool.exe
rm release_package/ConsoleReconstruction.exe
rm release_package/MultiViewReconstruction.exe
rm release_package/MultiViewReconstructionRealSense.exe
rm release_package/QtReconstruction.exe
rm release_package/RealSenseReconstruction.exe
"C:\Program Files\7-Zip\7z.exe" a sensor-laser-test_release.zip release_package/.
rm release_package/ -rf
