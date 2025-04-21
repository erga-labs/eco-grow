export const getCrops = async (event) => {
    const resp = await fetch("/api/crops");
    const respJson = await resp.json();
    return respJson;
};

export const isOk = (current, { max, min }) => {
    return current >= min && current <= max;
};
