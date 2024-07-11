#include <cstdint>
#include <string>

class Joker{
private:
  std::string description;
  uint8_t data;
public:
  void setDescription(std::string text);
  void setEdition(int edition);
  void setRarity(int rarity);
  void setActivateOn(int activation_code);

  void toString();

  std::string getDescription();
  uint8_t getData();
  int getEdition();
  int getRarity();
  int getActivatedOn();

  Joker(int activation_code, int rarity, int edition);
};
