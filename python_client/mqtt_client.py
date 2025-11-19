import paho.mqtt.client as mqtt

BROKER = "broker.hivemq.com"
TOPIC = "robot/cmd"

def main():
    client = mqtt.Client()
    client.connect(BROKER, 1883, 60)

    print("Connected to MQTT broker.")
    print("Enter commands like:")
    print("  motor:100:1")
    print("  led:on")
    print("  led:off")

    while True:
        cmd = input("> ").strip()
        if cmd == "":
            continue
        client.publish(TOPIC, cmd)
        print("Sent:", cmd)

if __name__ == "__main__":
    main()
