export const classifyImage = async (base64Image) => {
    try {
        const resp = await fetch("/api/classify", {
            method: "POST",
            headers: {
                "Content-Type": "application/json",
            },
            body: JSON.stringify({ image: base64Image }),
        });

        if (!resp.ok) {
            throw new Error(`API responded with status: ${resp.status}`);
        }

        const respJson = await resp.json();
        return respJson;
    } catch (error) {
        console.error("Error in classifyImage:", error);
        throw error;
    }
};