# Geant4 Spallation Simulation for BL4S 2026

## Project Overview
This repository contains a Monte Carlo simulation developed for the **Beamline for Schools (BL4S)** competition. 
The simulation investigates neutron spallation processes in a custom high-entropy alloy target.

### Technical Details
* **Target Material:** AlCrFeMnSi (Lightweight aerospace alloy).
* **Beam:** 1 GeV Neutrons.
* **Physics List:** QGSP_BERT_HP (High-precision hadronic physics).
* **Goal:** Analysis of secondary neutron angular distribution and shielding efficiency.

## How to Build
1. Create a build directory: `mkdir build && cd build`
2. Configure with CMake: `cmake ..`
3. Compile: `make`

## How to Run
* **Batch Mode (100k particles):** `./bl4s_sim run_batch.mac`
* **Plotting:** Use `python plot_angles.py` to visualize the results.