/*
Will contain functions required by the frontend regarding nutrients
These functions will actually call the API

- [X] getNutrientsForCrop
- [ ] getNutrientHistory
*/

export const getNutrientsForCrop = (crop) => {
    /*
    {
        nitrogen: { current: <T>, optimal: <T>, ok: boolean },
        pottasium: { current: <T>, optimal: <T>, ok: boolean },
        phosphorus: { current: <T>, optimal: <T>, ok: boolean },
        moisture: { current: <T>, optimal: <T>, ok: boolean },
    }
    */

    const r = () => Math.round(Math.random() * 100);

    // current and optimal can be a number or a string
    return {
        nitrogen: { current: r(), optimal: r(), ok: false },
        pottasium: { current: r(), optimal: r(), ok: true },
        phosphorus: { current: r(), optimal: r(), ok: true },
        moisture: { current: r(), optimal: r(), ok: true },
    };
};
