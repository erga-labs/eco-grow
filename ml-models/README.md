# EcoGrow Machine Learning Models

## Overview
Machine learning models for the EcoGrow Smart Agriculture System focusing on crop prediction, management, and health detection.

## Environment Setup
- Recent version of python 3 (tested on 3.12)
- Virtual Environment Recommended
- Uses keras with pytorch as its backend

## Installation
1. Clone the repository
2. Create virtual environment:
   ```bash
   python3 -m venv venv
   source venv/bin/activate  # On Windows use `venv\Scripts\activate`


## Project Structure
- `dataset/`: Dataset storage
- `saved-models/`: After training, models are stored here
- `*.ipynb`: Each notebook has implementation for its model

## Models

1. **Crop Management Advisor**
   - Recommends pesticides, irrigation strategies
   - Trained on agricultural best practices

> TO BE IMPLEMENTED

2. **Time Series Forecasting**
   - Predicts suitable crops based on environmental conditions
   - Uses LSTM and Time Series segmentation

3. **Crop Health Detection**
   - Image-based disease identification
   - Convolutional Neural Network (CNN) implementation

## Licensing
Refer to the project's main LICENSE file