export const getSensors = () => {
    return ["ABC-123", "DEF-456", "GHI-789"];
};

export const getDataForSensor = (sensorId) => {
    return {
        currentCrop: "Tomato",
        currentValues: {
            nitrogen: 100,
            potassium: 100,
            phosphorus: 100,
            moisture: 100,
        },
    };
};
