#include "a0008.h"

/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  this function will extract the last and first name from the full name
 *  and store them into the other two variables.
 *
 *  @param[str] fullName
 *  @param[str] first
 *  @param[str] last 
 *
 *  @returns nothing, this is a void function
 *
 *  @par Example
 *  @verbatim

    string fullName = "Anderson, Heidi";
    string last;
    string first;
    
    splitNameLF(fullName, first, last);
    
    REQUIRE( fullName == "Anderson, Heidi");
    REQUIRE( first == "Heidi");
    REQUIRE( last == "Anderson");

    @endverbatim
 ************************************************************************/

void splitNameLF(string fullName, string &first, string &last)
{
    int lastLen = fullName.find(", ");
    int firstPos = lastLen + 2;
    int len = fullName.length();
    int firstLen = len - lastLen - 1;
    
    last = fullName.substr(0, lastLen);
    first = fullName.substr(firstPos, firstLen);
    
}
/** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  this function will extract the last and first name from the full name
 *  and store them into the other two variables.
 *
 *  @param[str] fullName
 *  @param[str] first
 *  @param[str] last 
 *
 *  @returns nothing, this is a void function
 *
 *  @par Example
 *  @verbatim

    string fullName = "Savannah Flaherty";
    string last;
    string first;
    
    splitNameFL(fullName, first, last);
    
    REQUIRE( fullName == "Savannah Flaherty");
    REQUIRE( first == "Savannah");
    REQUIRE( last == "Flaherty");

    @endverbatim
 ************************************************************************/
void splitNameFL(string fullName, string &first, string &last)
{
    int firstLen = fullName.find(" ");
    int lastPos = firstLen + 1;
    int len = fullName.length();
    int lastLen = len - firstLen - 1;
    
    first = fullName.substr(0, firstLen);
    last = fullName.substr(lastPos, lastLen);
}
 /** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  this function will form an email address in the form of first.last@domain
  * and return this value.
 *
 *  @param[str] fullName
 *  @param[str] first
 *  @param[str] last 
 *  @param[str] domain
 *
 *  @returns str email
 *
 *  @par Example
 *  @verbatim

    string email;
    
    string first = "Owen";
    string last = "Sta";
    string domain = "mines.sdsmt.edu";
    
    email = createEmail(first, last, domain);
    
    REQUIRE(email == "Owen.Sta@mines.sdsmt.edu");
    @endverbatim
 ************************************************************************/
string createEmail(string first, string last, string domain)
{
    string email = first + "." + last + "@" + domain;
    
    return email;
}
 /** **********************************************************************
 *  @author Heidi Anderson
 *
 *  @par Description
 *  this function will call necessary functions that will compute, First Last
 *  Last, First and an email.
 *
 *  @param[str] mixed
 *  @param[str] firstLast
 *  @param[str] lastFirst 
 *  @param[str] email
 *  @param[int] size
 *  @param[str] domain
 *
 *  @returns nothing, this is a void function
 *
 *  @par Example
 *  @verbatim

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
    
    @endverbatim
 ************************************************************************/
void fixList(string mixed[], string firstLast[], string lastFirst[], string email[], int size, string domain)
{
    int i;
    string first;
    string last;
    
    
    for(i = 0; i < size; ++i)
    {
        if(mixed[i].find(",") == -1)
        {
            splitNameFL(mixed[i], first, last);
        }
        else
        {
            splitNameLF(mixed[i], first, last);
        }
        
        email[i] = createEmail(first, last, domain);
        
        firstLast[i] = first + " " + last;
        lastFirst[i] = last + ", " + first;
    }
}