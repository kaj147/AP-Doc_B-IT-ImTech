#include <iostream>
#include <memory>
using namespace std;

class Data {
public:
    string myContent= "my content";


};
class Holder {
public:
    Data myData;
    Data* myDataByOldStylePointer;
    std::unique_ptr<Data> myUniqueData;

    Holder() {
        myDataByOldStylePointer = new Data(); // Handmatige allocatie
        myUniqueData = std::make_unique<Data>();
    }

    ~Holder() {
        delete myDataByOldStylePointer; // Handmatige opruiming (gevaarlijk!)
    }
    //dit geeft een pointer terug die rechtstreeks verwijst naar het mydata object.
    //het gaat mijn data kunnen aanpassen
    Data* GetDataPointer(){return &myData;}
    //dit geeft een alias terug naar het mydata object
    //het gaat mijn data kunnen aanpassen.
    Data& GetDataByReference() {return myData;}
    //dit maakt een kopie van de data in myData
    //het gaat mijn data niet kunnen aanpassen.
    Data GetDataByValue(){return myData;}


    // 1. De Pointer variant (Adres kopiëren)
    // De ontvanger krijgt het adres. Ownership wijzigt niet.
    // Dit is wat je nu waarschijnlijk doet.
    Data* GetOldDataAsPointer() {
        return myDataByOldStylePointer;
    }

    // 2. De Reference variant (Dereferencen naar Alias)
    // Je "pelt" de pointer af met * om de data als alias aan te bieden.
    // Dit voelt voor de gebruiker veiliger (geen pijl-operator nodig).
    Data& GetOldDataAsReference() {
        return *myDataByOldStylePointer;
    }

    // 3. De Value variant (Dereferencen naar Kopie)
    // Je haalt de data op en maakt er een gloednieuwe kopie van.
    // De ontvanger kan prutsen wat hij wil, het origineel blijft gelijk.
    Data GetOldDataAsValue() {
        return *myDataByOldStylePointer;
    }

    // 1. De "Kijk-maar-niet-aankomen" variant (Lenen via Pointer)
    // Gebruik .get() om het ruwe adres uit de smart pointer te halen.
    // Ownership blijft bij de klasse.
    Data* GetUniqueDataPointer() { return myUniqueData.get(); }

    // 2. De "Lenen via Reference" variant (Lenen via Alias)
    // We de-referencen de smart pointer met * om de data zelf als reference door te geven.
    Data& GetUniqueDataByReference() { return *myUniqueData; }

    // 3. De "Weggeef" variant (Ownership transfer)
    // Er bestaat GEEN 'By Value' (kopie) voor unique_ptr.
    // De enige optie is verhuizen via std::move.
    std::unique_ptr<Data> GiveAwayUniqueData() { return std::move(myUniqueData); }



    string readData(){return myData.myContent;}
    string readUniqueData(){return myUniqueData->myContent;}
    string readOldData(){return myDataByOldStylePointer->myContent;}
};