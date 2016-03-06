#include <secsy/secsy.h>

#define LOG(format, ...) do { printf(format, ##__VA_ARGS__); } while (0)
#define LOG_VALUE(action, value) do { LOG("%s: %s\n", (action), (value)); } while (0)
#define LOG_ACTION(action, result) do { LOG_VALUE(action, (result) ? "true" : "false"); } while (0)

class NotAComponent {};
class FirstComponent : public secsy::Component {};
class SecondComponent : public secsy::Component {};

int main(int argc, char *argv[]) {
    secsy::World world;

    secsy::Entity *entity = world.CreateEntity();

    return 0;
}
