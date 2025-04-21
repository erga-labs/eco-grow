export const getCrops = async (event) => {
    const resp = await fetch("/api/crops");
    const respJson = await resp.json();
    return respJson;
};

export const isOk = (current, optimal) => {
    return Math.random() > 0.5;
};
