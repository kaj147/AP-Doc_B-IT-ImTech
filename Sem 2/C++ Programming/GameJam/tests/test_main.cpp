#include <catch2/catch_test_macros.hpp>
#include "Held.h"
#include "TestableClasses.h"

TEST_CASE("sanity check", "[Setup]")
{
    Game::Held m = Game::Held();

    REQUIRE_NOTHROW(m.GetPosition());
}

TEST_CASE("Held", "[Held][spawnposition][x]") {
    Game::Held _hero = Game::Held();
    SECTION("positie") {
        SECTION("X") {
            SECTION("Groterdan 0") {
                REQUIRE(_hero.GetPosition().x>0);
            }
            SECTION("kleinerdan 800") {
                REQUIRE(_hero.GetPosition().x<800);
            }
        }
    }
}

TEST_CASE("Holder", "[Holder]")
{
    SECTION("INSTANTIE")
    {
        Holder hold = Holder();
        auto pointer = hold.GetDataPointer();

        pointer->myContent = "Gehackt door een pointer";

        REQUIRE(hold.readData() == "Gehackt door een pointer");
    }
}

TEST_CASE("Unsafe Objects", "[Object]")
{
    SECTION("GetDataPointer")
    {
        Holder hold = Holder();

        auto data = hold.GetDataPointer();
        data->myContent = "Gehackt door een pointer";

        REQUIRE(hold.readData() == "my content");
    }

    SECTION("GetDataByReference")
    {
        Holder hold = Holder();

        auto data = hold.GetDataByReference();
        data.myContent = "Gehackt door een pointer";

        REQUIRE(hold.readData() == "my content");
    }

    SECTION("GetDataByValue")
    {
        Holder hold = Holder();

        auto data = hold.GetDataByValue();
        data.myContent = "Gehackt door een pointer";

        REQUIRE(hold.readData() == "my content");
    }

    SECTION("GetOldDataAsPointer")
    {
        Holder hold = Holder();

        auto data = hold.GetOldDataAsPointer();
        data->myContent = "Gehackt door een pointer";

        REQUIRE(hold.readOldData() == "my content");
    }

    SECTION("GetOldDataAsReference")
    {
        Holder hold = Holder();

        auto data = hold.GetOldDataAsReference();
        data.myContent = "Gehackt door een pointer";

        REQUIRE(hold.readOldData() == "my content");
    }

    SECTION("GetOldDataAsValue")
    {
        Holder hold = Holder();

        auto data = hold.GetOldDataAsValue();
        data.myContent = "Gehackt door een pointer";

        REQUIRE(hold.readOldData() == "my content");
    }

    SECTION("GetUniqueDataPointer")
    {
        Holder hold = Holder();

        auto data = hold.GetUniqueDataPointer();
        data->myContent = "Gehackt door een pointer";

        REQUIRE(hold.readUniqueData() == "my content");
    }

    SECTION("GetUniqueDataByReference")
    {
        Holder hold = Holder();

        auto data = hold.GetUniqueDataByReference();
        data.myContent = "Gehackt door een pointer";

        REQUIRE(hold.myUniqueData == nullptr);
    }
}
