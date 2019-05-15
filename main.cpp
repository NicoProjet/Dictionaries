#include <iostream>

#include<DictionaryTrie.h>
#include<DictionaryList.h>
#include<DictionaryVector.h>

int main()
{



    // Tries
    std::cout << "\n   ++++++++++++++++" << std::endl;
    std::cout << "   ++++  Trie  ++++" << std::endl;
    std::cout << "   ++++++++++++++++\n" << std::endl;
    std::cout << "\n\n ---  Insertion Tests  ----\n" << std::endl;

    DictionaryTrie t;
    t.insert("kayak"); std::cout << "t(" << t.size() << ") = " << t << std::endl;
    t.insert("avion"); std::cout << "t(" << t.size() << ") = " << t << std::endl;
    t.insert("voiture"); std::cout << "t(" << t.size() << ") = " << t << std::endl;
    t.insert("moto"); std::cout << "t(" << t.size() << ") = " << t << std::endl;
    t.insert("velo"); std::cout << "t(" << t.size() << ") = " << t << std::endl;
    std::cout << "try to insert 'kayak' again: ";
    t.insert("kayak"); std::cout << "t(" << t.size() << ") = " << t << std::endl;


    std::cout << "\n\n ---  Find Tests  ----\n" << std::endl;
    std::cout << "Reminder, dictionary = " << t << std::endl;
    std::cout << "alger in dictionary: " << t.isIn("alger") << std::endl;
    std::cout << "kayak in dictionary: " << t.isIn("kayak") << std::endl;
    std::cout << "avion in dictionary: " << t.isIn("avion") << std::endl;
    std::cout << "kay in dictionary: " << t.isIn("kay") << std::endl;
    std::cout << "lo in dictionary: " << t.isIn("lo") << std::endl;


    std::cout << "\n\n ---  Erase Tests  ----\n" << std::endl;
    std::cout << "Reminder, dictionary = " << "t(" << t.size() << ") = " << t << std::endl;
    t.erase("moto");
    std::cout << "erase 'moto' ... dictionary = " << "t(" << t.size() << ") = " << t << std::endl;
    t.erase("velo");
    std::cout << "erase 'velo' ... dictionary = " << "t(" << t.size() << ") = " << t << std::endl;
    t.insert("moto"); t.insert("velo"); t.insert("kayakayak"); t.insert("voiturette");
    std::cout << "insert moto, velo, kayakayak and voiturette ... \n dictionary = " << "t(" << t.size() << ") = " << t << std::endl;
    t.erase("kayak");
    std::cout << "erase 'kayak' ... dictionary = " << "t(" << t.size() << ") = " << t << std::endl;
    t.erase("voiturette");
    std::cout << "erase 'voiturette' ... dictionary = " << "t(" << t.size() << ") = " << t << std::endl;


    std::cout << "\n\n ---  Copy Tests  ----\n" << std::endl;
    std::cout << "Reminder, dictionary = " << t << std::endl;
    DictionaryTrie t2;
    t2 = t;
    std::cout << "Trie t2 = t" << std::endl;
    std::cout << "t(" << t.size() << ") = " << t << std::endl;
    std::cout << "t2(" << t2.size() << ") = " << t2 << std::endl;
    t2.insert("bateau"); t2.insert("ski");
    std::cout << "insert bateau and ski in t2 ..." << std::endl;
    std::cout << "t2(" << t2.size() << ") = " << t2 << std::endl;
    std::cout << "t(" << t.size() << ") = " << t << std::endl;


    std::cout << "\n\n ---  Move Tests  ----\n" << std::endl;
    std::cout << "Reminder, dictionary = " << t << std::endl;
    t2.clear();
    std::cout << "t2(" << t2.size() << ") = " << t2 << std::endl;
    std::cout << ">>> t2 = std::move(t);" << std::endl;
    t2 = std::move(t);
    std::cout << "t(" << t.size() << ") = " << t << std::endl;
    std::cout << "t2(" << t2.size() << ") = " << t2 << std::endl;




    // List
    std::cout << "\n   ++++++++++++++++" << std::endl;
    std::cout << "   ++++  List  ++++" << std::endl;
    std::cout << "   ++++++++++++++++\n" << std::endl;

    std::cout << "\n\n ---  Insertion Tests  ----\n" << std::endl;

    DictionaryList l;
    std::cout << l << std::endl;
    l.insert("kayak"); std::cout << "t(" << l.size() << ") = " << l << std::endl;
    l.insert("avion"); std::cout << "t(" << l.size() << ") = " << l << std::endl;
    l.insert("voiture"); std::cout << "t(" << l.size() << ") = " << l << std::endl;
    l.insert("moto"); std::cout << "t(" << l.size() << ") = " << l << std::endl;
    l.insert("velo"); std::cout << "t(" << l.size() << ") = " << l << std::endl;
    std::cout << "try to insert 'kayak' again: ";
    l.insert("kayak"); std::cout << "t(" << l.size() << ") = " << l << std::endl;

    std::cout << "\n\n ---  Find Tests  ----\n" << std::endl;
    std::cout << "Reminder, dictionary = " << l << std::endl;
    std::cout << "alger in dictionary: " << l.isIn("alger") << std::endl;
    std::cout << "kayak in dictionary: " << l.isIn("kayak") << std::endl;
    std::cout << "avion in dictionary: " << l.isIn("avion") << std::endl;
    std::cout << "kay in dictionary: " << l.isIn("kay") << std::endl;
    std::cout << "lo in dictionary: " << l.isIn("lo") << std::endl;

    std::cout << "\n\n ---  Erase Tests  ----\n" << std::endl;
    std::cout << "Reminder, dictionary = " << "l(" << l.size() << ") = " << l << std::endl;
    l.erase("moto");
    std::cout << "erase 'moto' ... dictionary = " << "l(" << l.size() << ") = " << l << std::endl;
    l.erase("velo");
    std::cout << "erase 'velo' ... dictionary = " << "l(" << l.size() << ") = " << l << std::endl;
    l.insert("moto"); l.insert("velo"); l.insert("kayakayak"); l.insert("voiturette");
    std::cout << "insert moto, velo, kayakayak and voiturette ... \n dictionary = " << "l(" << l.size() << ") = " << l << std::endl;
    l.erase("kayak");
    std::cout << "erase 'kayak' ... dictionary = " << "l(" << l.size() << ") = " << l << std::endl;
    l.erase("voiturette");
    std::cout << "erase 'voiturette' ... dictionary = " << "l(" << l.size() << ") = " << l << std::endl;


    std::cout << "\n\n ---  Copy Tests  ----\n" << std::endl;
    std::cout << "Reminder, dictionary = " << l << std::endl;
    DictionaryList l2;
    l2 = l;
    std::cout << "Trie l2 = l" << std::endl;
    std::cout << "l(" << l.size() << ") = " << l << std::endl;
    std::cout << "l2(" << l2.size() << ") = " << l2 << std::endl;
    l2.insert("bateau"); l2.insert("ski");
    std::cout << "insert bateau and ski in l2 ..." << std::endl;
    std::cout << "l2(" << l2.size() << ") = " << l2 << std::endl;
    std::cout << "l(" << l.size() << ") = " << l << std::endl;


    std::cout << "\n\n ---  Move Tests  ----\n" << std::endl;
    std::cout << "Reminder, dictionary = " << l << std::endl;
    l2.clear();
    std::cout << "l2(" << l2.size() << ") = " << l2 << std::endl;
    std::cout << ">>> l2 = std::move(l);" << std::endl;
    l2 = std::move(l);
    std::cout << "l(" << l.size() << ") = " << l << std::endl;
    std::cout << "l2(" << l2.size() << ") = " << l2 << std::endl;




    std::cout << "\n   +++++++++++++++++" << std::endl;
    std::cout << "   ++++  Merge  ++++" << std::endl;
    std::cout << "   +++++++++++++++++\n" << std::endl;

    t.insert("kayak");
    t.insert("avion");
    t.insert("voiture");
    t.insert("moto");
    t.insert("velo");

    l.insert("kayak");
    l.insert("aviron");
    l.insert("camion");
    l.insert("moto");
    l.insert("skate");

    std::cout << "t(" << t.size() << ") = " << t << std::endl;
    std::cout << "l(" << l.size() << ") = " << l << std::endl;
    std::cout << ">>> t+= l" << std::endl;
    t += l;
    std::cout << "t(" << t.size() << ") = " << t << std::endl;
    std::cout << "l(" << l.size() << ") = " << l << std::endl;

    // reset
    std::cout << "\n RESET DICTIONARIES \n" << std::endl;
    t.clear(); l.clear();

    t.insert("kayak");
    t.insert("avion");
    t.insert("voiture");
    t.insert("moto");
    t.insert("velo");

    l.insert("kayak");
    l.insert("aviron");
    l.insert("camion");
    l.insert("moto");
    l.insert("skate");

    std::cout << "t(" << t.size() << ") = " << t << std::endl;
    std::cout << "l(" << l.size() << ") = " << l << std::endl;
    std::cout << ">>> l += t" << std::endl;
    l += t;
    std::cout << "t(" << t.size() << ") = " << t << std::endl;
    std::cout << "l(" << l.size() << ") = " << l << std::endl;

    std::cout << "\n   +++++++++++++++++++" << std::endl;
    std::cout << "   ++++  Vectors  ++++" << std::endl;
    std::cout << "   +++++++++++++++++++\n" << std::endl;

    std::cout << "\n\n ---  Insertion Tests  ----\n" << std::endl;

    DictionaryVector v;
    v.insert("kayak"); std::cout << "v(" << v.size() << ") = " << v << std::endl;
    v.insert("avion"); std::cout << "v(" << v.size() << ") = " << v << std::endl;
    v.insert("voiture"); std::cout << "v(" << v.size() << ") = " << v << std::endl;
    v.insert("moto"); std::cout << "v(" << v.size() << ") = " << v << std::endl;
    v.insert("velo"); std::cout << "v(" << v.size() << ") = " << v << std::endl;
    std::cout << "try to insert 'kayak' again: ";
    v.insert("kayak"); std::cout << "v(" << v.size() << ") = " << v << std::endl;

    std::cout << "\n\n ---  Erase Tests  ----\n" << std::endl;
    std::cout << "Reminder, dictionary = " << "v(" << v.size() << ") = " << v << std::endl;
    v.erase("moto");
    std::cout << "erase 'moto' ... dictionary = " << "v(" << v.size() << ") = " << v << std::endl;
    v.erase("voiture");
    std::cout << "erase 'voiture' ... dictionary = " << "v(" << v.size() << ") = " << v << std::endl;
    v.insert("moto"); v.insert("kayakayak"); v.insert("voiturette");
    std::cout << "insert moto, kayakayak and voiturette ... \n dictionary = " << "v(" << v.size() << ") = " << v << std::endl;
    v.erase("kayak");
    std::cout << "erase 'kayak' ... dictionary = " << "v(" << v.size() << ") = " << v << std::endl;
    v.erase("voiturette");
    std::cout << "erase 'voiturette' ... dictionary = " << "v(" << v.size() << ") = " << v << std::endl;

    std::cout << "\n\n ---  Find Tests  ----\n" << std::endl;
    std::cout << "Reminder, dictionary = " << v << std::endl;
    std::cout << "alger in dictionary: " << v.isIn("alger") << std::endl;
    std::cout << "kayak in dictionary: " << v.isIn("kayak") << std::endl;
    std::cout << "avion in dictionary: " << v.isIn("avion") << std::endl;
    std::cout << "kay in dictionary: " << v.isIn("kay") << std::endl;
    std::cout << "lo in dictionary: " << v.isIn("lo") << std::endl;

    std::cout << "\n\n ---  Copy Tests  ----\n" << std::endl;
    std::cout << "Reminder, dictionary = " << v << std::endl;
    DictionaryVector v2;
    v2 = v;
    std::cout << "Trie v2 = v" << std::endl;
    std::cout << "v(" << v.size() << ") = " << v << std::endl;
    std::cout << "v2(" << v2.size() << ") = " << v2 << std::endl;
    v2.insert("bateau"); v2.insert("ski");
    std::cout << "insert bateau and ski in v2 ..." << std::endl;
    std::cout << "v2(" << v2.size() << ") = " << v2 << std::endl;
    std::cout << "v(" << v.size() << ") = " << v << std::endl;


    std::cout << "\n\n ---  Move Tests  ----\n" << std::endl;
    std::cout << "Reminder, dictionary = " << v << std::endl;
    v2.clear();
    std::cout << "v2(" << v2.size() << ") = " << v2 << std::endl;
    std::cout << ">>> v2 = std::move(v);" << std::endl;
    v2 = std::move(v);
    std::cout << "v(" << v.size() << ") = " << v << std::endl;
    std::cout << "v2(" << v2.size() << ") = " << v2 << std::endl;

    std::cout << "\n   +++++++++++++++++" << std::endl;
    std::cout << "   ++++  Merge  ++++" << std::endl;
    std::cout << "   +++++++++++++++++\n" << std::endl;
    std::cout << "clear vector and insert: vehicule, ski, canoe, planeur et jetski" << std::endl;
    v.clear();
    v.insert("vehicule"); v.insert("ski"); v.insert("canoe"); v.insert("planeur");v.insert("jetski");
    std::cout << "v(" << v.size() << ") = " << v << std::endl;
    std::cout << ">>> v += l (previously l += t)" << std::endl;
    v += l;
    std::cout << "v(" << v.size() << ") = " << v << std::endl;
    std::cout << ">>> t += v" << std::endl;
    t += v;
    std::cout << "v(" << v.size() << ") = " << v << std::endl;
    std::cout << "t(" << t.size() << ") = " << t << std::endl;




    return 0;
}
