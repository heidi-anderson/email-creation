#define CATCH_CONFIG_MAIN
#include "..\\catch.hpp"
#include "a0008.h"



TEST_CASE( "splitNameLF - Rubble, Barney")
{
    string fullName = "Rubble, Barney";
    string last;
    string first;
    
    splitNameLF(fullName, first, last);
    
    REQUIRE( fullName == "Rubble, Barney");
    REQUIRE( first == "Barney");
    REQUIRE( last == "Rubble");
}

TEST_CASE( "splitNameLF - Anderson, Heidi")
{
    string fullName = "Anderson, Heidi";
    string last;
    string first;
    
    splitNameLF(fullName, first, last);
    
    REQUIRE( fullName == "Anderson, Heidi");
    REQUIRE( first == "Heidi");
    REQUIRE( last == "Anderson");
}

TEST_CASE( "splitNameLF - Bieber, Justin")
{
    string fullName = "Bieber, Justin";
    string last;
    string first;
    
    splitNameLF(fullName, first, last);
    
    REQUIRE( fullName == "Bieber, Justin");
    REQUIRE( first == "Justin");
    REQUIRE( last == "Bieber");
}

TEST_CASE( "splitNameFL - Barney Rubble")
{
    string fullName = "Barney Rubble";
    string last;
    string first;
    
    splitNameFL(fullName, first, last);
    
    REQUIRE( fullName == "Barney Rubble");
    REQUIRE( first == "Barney");
    REQUIRE( last == "Rubble");
}

TEST_CASE( "splitNameFL - Heidi Anderson")
{
    string fullName = "Heidi Anderson";
    string last;
    string first;
    
    splitNameFL(fullName, first, last);
    
    REQUIRE( fullName == "Heidi Anderson");
    REQUIRE( first == "Heidi");
    REQUIRE( last == "Anderson");
}

TEST_CASE( "splitNameFL - Savannah Flaherty")
{
    string fullName = "Savannah Flaherty";
    string last;
    string first;
    
    splitNameFL(fullName, first, last);
    
    REQUIRE( fullName == "Savannah Flaherty");
    REQUIRE( first == "Savannah");
    REQUIRE( last == "Flaherty");
}

TEST_CASE("createEmail - Fred Flinstone")
{
    string email;
    
    string first = "Fred";
    string last = "Flinstone";
    string domain = "mines.sdsmt.edu";
    
    email = createEmail(first, last, domain);
    
    REQUIRE(email == "Fred.Flinstone@mines.sdsmt.edu");
}

TEST_CASE("createEmail - Abby Strahl")
{
    string email;
    
    string first = "Abby";
    string last = "Strahl";
    string domain = "mines.sdsmt.edu";
    
    email = createEmail(first, last, domain);
    
    REQUIRE(email == "Abby.Strahl@mines.sdsmt.edu");
}

TEST_CASE("createEmail - Owen Sta")
{
    string email;
    
    string first = "Owen";
    string last = "Sta";
    string domain = "mines.sdsmt.edu";
    
    email = createEmail(first, last, domain);
    
    REQUIRE(email == "Owen.Sta@mines.sdsmt.edu");
}

TEST_CASE("fixList - 3 items")
{
    string mixed[3] = { "Fred Flinstone", "Rubble, Barney", "Flinstone, Wilma" };
    
    string firstLast[3];
    string lastFirst[3];
    string email[3];
    
    string domainName = "mines.sdsmt.edu";
    fixList( mixed, firstLast, lastFirst, email, 3, domainName);
    
    REQUIRE( mixed[0] == "Fred Flinstone");
    REQUIRE( firstLast[0] == "Fred Flinstone");
    REQUIRE( lastFirst[0] == "Flinstone, Fred");
    REQUIRE( email[0] == "Fred.Flinstone@mines.sdsmt.edu");
    
    REQUIRE( mixed[1] == "Rubble, Barney");
    REQUIRE( firstLast[1] == "Barney Rubble");
    REQUIRE( lastFirst[1] == "Rubble, Barney");
    REQUIRE( email[1] == "Barney.Rubble@mines.sdsmt.edu");
    
    REQUIRE( mixed[2] == "Flinstone, Wilma");
    REQUIRE( firstLast[2] == "Wilma Flinstone");
    REQUIRE( lastFirst[2] == "Flinstone, Wilma");
    REQUIRE( email[2] == "Wilma.Flinstone@mines.sdsmt.edu");
}

TEST_CASE("fixList - 2 items")
{
    string mixed[2] = { "Heidi Anderson", "Stelzer, Olivia" };
    
    string firstLast[2];
    string lastFirst[2];
    string email[2];
    
    string domainName = "mines.sdsmt.edu";
    fixList( mixed, firstLast, lastFirst, email, 2, domainName);
    
    REQUIRE( mixed[0] == "Heidi Anderson");
    REQUIRE( firstLast[0] == "Heidi Anderson");
    REQUIRE( lastFirst[0] == "Anderson, Heidi");
    REQUIRE( email[0] == "Heidi.Anderson@mines.sdsmt.edu");
    
    REQUIRE( mixed[1] == "Stelzer, Olivia");
    REQUIRE( firstLast[1] == "Olivia Stelzer");
    REQUIRE( lastFirst[1] == "Stelzer, Olivia");
    REQUIRE( email[1] == "Olivia.Stelzer@mines.sdsmt.edu");
}

TEST_CASE("fixList - 5 items")
{
    string mixed[5] = { "Michael Anderson", "Classen, Kari", "Anderson, Heidi", "Yairis Alvarado", "Sam Smith" };
    
    string firstLast[5];
    string lastFirst[5];
    string email[5];
    
    string domainName = "mines.sdsmt.edu";
    fixList( mixed, firstLast, lastFirst, email, 5, domainName);
    
    REQUIRE( mixed[0] == "Michael Anderson");
    REQUIRE( firstLast[0] == "Michael Anderson");
    REQUIRE( lastFirst[0] == "Anderson, Michael");
    REQUIRE( email[0] == "Michael.Anderson@mines.sdsmt.edu");
    
    REQUIRE( mixed[1] == "Classen, Kari");
    REQUIRE( firstLast[1] == "Kari Classen");
    REQUIRE( lastFirst[1] == "Classen, Kari");
    REQUIRE( email[1] == "Kari.Classen@mines.sdsmt.edu");
    
    REQUIRE( mixed[2] == "Anderson, Heidi");
    REQUIRE( firstLast[2] == "Heidi Anderson");
    REQUIRE( lastFirst[2] == "Anderson, Heidi");
    REQUIRE( email[2] == "Heidi.Anderson@mines.sdsmt.edu");
    
    REQUIRE( mixed[3] == "Yairis Alvarado");
    REQUIRE( firstLast[3] == "Yairis Alvarado");
    REQUIRE( lastFirst[3] == "Alvarado, Yairis");
    REQUIRE( email[3] == "Yairis.Alvarado@mines.sdsmt.edu");
    
    REQUIRE( mixed[4] == "Sam Smith");
    REQUIRE( firstLast[4] == "Sam Smith");
    REQUIRE( lastFirst[4] == "Smith, Sam");
    REQUIRE( email[4] == "Sam.Smith@mines.sdsmt.edu");
}