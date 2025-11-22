import paho.mqtt.client as mqtt

BROKER = "broker.hivemq.com"
TOPIC = "robot/cmd"

# def on_connect(client, userdata, flags, rc):
#   if rc == 0:
#        print("✓ Successfully connected to MQTT broker.")
#    else:
#        print("✗ Failed to connect. Error code:", rc) 

def main():
    client = mqtt.Client()
# client.on_connect = on_connect
    
    client.connect(BROKER, 1883, 60)
# client.loop_start() 

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
