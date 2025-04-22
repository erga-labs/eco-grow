import { json } from "@sveltejs/kit";

export async function GET() {
    const data = `2025-04-22 22:00:00 INFO Device started successfully. Device ID: IoT-Device-001
2025-04-22 22:05:15 DEBUG Sensor reading: Temperature=24.5°C, Humidity=40%
2025-04-22 22:10:30 INFO Data packet sent to server. Packet ID: 12345
2025-04-22 22:15:45 WARN Battery level low: 15%
2025-04-22 22:20:00 ERROR Sensor timeout detected. Attempting to reset sensor.
2025-04-22 22:21:10 INFO Sensor reset successful.
2025-04-22 22:25:00 DEBUG Sensor reading: Temperature=24.7°C, Humidity=39%
2025-04-22 22:30:00 INFO Firmware update check: No updates available.
2025-04-22 22:35:00 INFO Data packet sent to server. Packet ID: 12346
2025-04-22 22:40:00 INFO Device entering sleep mode to conserve power.
2025-04-22 22:45:00 INFO Device woke up from sleep mode.
2025-04-22 22:50:00 DEBUG Sensor reading: Temperature=24.6°C, Humidity=38%
2025-04-22 22:55:00 INFO Data packet sent to server. Packet ID: 12347
2025-04-22 23:00:00 INFO Device heartbeat signal sent.
`;

    return json({ data });
}
