#include "catch.hpp"
#include <string>
using std::string;
#include <list>
using std::list;

struct Character{
    string _characterName = "Thug";
    int _characterHealth = 2;
    string _weaponName = "fists";
    int _weaponDamage = 2;
    string _armorName = "ragged clothes";
    int _armorDefense = 0;
};

bool operator==(const Character& a, const Character& b){
    return (a._characterName == b._characterName) && (a._characterHealth == b._characterHealth)
           && (a._weaponName == b._weaponName) && (a._weaponDamage == b._weaponDamage)
           && (a._armorName == b._armorName) && (a._armorDefense == b._armorDefense);
}
bool operator!=(const Character& a, const Character& b){
    return (a._characterName != b._characterName) || (a._characterHealth != b._characterHealth)
        || (a._weaponName != b._weaponName) || (a._weaponDamage != b._weaponDamage)
        || (a._armorName != b._armorName) || (a._armorDefense != b._armorDefense);
}

//sort characters by their health
bool operator<(const Character& a, const Character& b){
    return (a._characterHealth < b._characterHealth);
}

TEST_CASE("Characters are set right", "[list]") {

    Character genericCharacter; // should be set to default "Thug" character

    REQUIRE(genericCharacter._characterName == "Thug");
    REQUIRE(genericCharacter._characterHealth == 2);
    REQUIRE(genericCharacter._weaponName == "fists");
    REQUIRE(genericCharacter._weaponDamage == 2);
    REQUIRE(genericCharacter._armorName == "ragged clothes");
    REQUIRE(genericCharacter._armorDefense == 0);
    Character characterMainCharacter;
    characterMainCharacter._characterName = "MainCharacter";
    characterMainCharacter._characterHealth = 20;
    characterMainCharacter._weaponName = "sword";
    characterMainCharacter._weaponDamage = 90;
    characterMainCharacter._armorName = "magic robes";
    characterMainCharacter._armorDefense = 15;
    Character characterTank;
    characterTank._characterName = "tank";
    characterTank._characterHealth = 80;
    characterTank._weaponName = "hammer";
    characterTank._weaponDamage = 30;
    characterTank._armorName = "shield";
    characterTank._armorDefense = 90;
    Character characterHealer;
    characterHealer._characterName = "healer";
    characterHealer._characterHealth = 15;
    characterHealer._weaponName = "magic";
    characterHealer._weaponDamage = -15;
    characterHealer._armorName = "shirt";
    characterHealer._armorDefense = 5;

    list<Character> characterList;
    characterList.push_back(characterMainCharacter);
    // ^^ list = (MainCharacter) ^^
    characterList.push_back(characterTank);
    // ^^ list = (MainCharacter, Tank) ^^
    REQUIRE(characterList.front() == characterMainCharacter);
    REQUIRE(characterList.back() == characterTank);
    characterList.push_back(characterHealer);
    // ^^ list = (MainCharacter, Tank, Healer) ^^
    REQUIRE((characterList.back() == characterHealer));
    characterList.pop_front();
    // ^^ list = (Tank, Healer) ^^
    REQUIRE(characterList.front() == characterTank);
    characterList.push_back(genericCharacter);
    // ^^ list = (Tank, Healer, generic) ^^
    REQUIRE(characterList.back() == genericCharacter);
    characterList.pop_back();
    // ^^ list = (Tank, Healer) ^^
    REQUIRE(characterList.back() == characterHealer);
    characterList.push_back(genericCharacter);
    // ^^ list = (Tank, Healer, generic)
    characterList.sort();
    // generic health = 2. Tank health = 80, Healer health = 15
    // list = (generic, Healer, Tank)
    REQUIRE(characterList.front() == genericCharacter);
    REQUIRE((characterList.back() == characterTank));
}