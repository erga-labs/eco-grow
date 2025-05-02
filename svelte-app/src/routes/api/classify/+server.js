import { env } from "$env/dynamic/private";

export async function POST({ request }) {
    try {
        // Parse the JSON body
        const requestData = await request.json();
        const base64Image = requestData.image;

        if (!base64Image) {
            return new Response(JSON.stringify({ error: "No image data provided" }), {
                status: 400,
                headers: { "Content-Type": "application/json" },
            });
        }

        // Send request to your FastAPI endpoint
        const response = await fetch(env.API_ENDPOINT || "/mp/predict/", {
            method: "POST",
            headers: {
                "Content-Type": "application/json",
                "X-API-Key": env.API_KEY,
            },
            body: JSON.stringify({
                base64_image: base64Image,
            }),
        });

        if (!response.ok) {
            console.error("API error:", response.status, await response.text());
            return new Response(JSON.stringify({ error: "Failed to classify image" }), {
                status: 500,
                headers: { "Content-Type": "application/json" },
            });
        }

        const data = await response.json();
        return new Response(JSON.stringify(data), {
            status: 200,
            headers: { "Content-Type": "application/json" },
        });
    } catch (error) {
        console.error("Server error:", error);
        return new Response(JSON.stringify({ error: error.message || "Internal server error" }), {
            status: 500,
            headers: { "Content-Type": "application/json" },
        });
    }
}
