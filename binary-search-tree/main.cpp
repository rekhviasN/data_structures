/*
 * Do not modify this file
 */

#include "main.h"

int main(int argc, char** argv) {
    srand(time(NULL));

    /*
     *  test data
     */
    int tempid, searchidx;
    Data tempData;
    int ids1[TESTDATA1] = {60, 20, 70, 40, 10, 50, 30};
    string strings1[TESTDATA1] = {"sixty", "twenty", "seventy", "forty", "ten", "fifty", "thirty"};
    int ids2[TESTDATA2] = {5, 15, 25, 35, 45, 55};
    string strings2[TESTDATA2] = {"five", "fifteen", "twenty five", "thirty five", "forty five", "fifty five"};

    /*
     *  make and display tree
     */
    BinTree *binSearchTree = new BinTree;
    cout << endl << "Binary Search Tree created" << endl << endl;
    binSearchTree->displayTree();

    /*
     *  testing methods on empty tree
     */
    cout << "Testing removeNode() on empty tree" << endl;
    cout << "==============================================" << endl;
    tempid = 10;
    cout << "removing " << tempid << "... ";
    binSearchTree->removeNode(tempid) ? cout << "removed" << endl : cout << "failed" << endl;
    cout << endl;

    cout << "Testing getRootData() on empty tree" << endl;
    cout << "==============================================" << endl;
    if (binSearchTree->getRootData(&tempData)) {
        cout << "retrieved " << tempData.id << " " << tempData.information << endl;
    } else {
        cout << "NOT retrieved " << tempData.id << " " << tempData.information << endl;
    }
    cout << endl;

    cout << "Testing contains() and getNode() on empty tree" << endl;
    cout << "==============================================" << endl;
    tempid = random_range(10, 100);
    binSearchTree->contains(tempid) ? cout << "contains " << tempid : cout << "does NOT contain " << tempid;
    cout << endl;
    if (binSearchTree->getNode(&tempData, tempid)) {
        cout << "retrieved: " << tempData.id << " " << tempData.information << endl;
    } else {
        cout << "NOT found: " << tempid << endl;
    }
    cout << endl;

    /*
     *  filling tree with test data and displaying
     */
    cout << "Filling Tree" << endl;
    cout << "==============================================" << endl;
    for (int i = 0; i < TESTDATA1; i++) {
        cout << "adding " << ids1[i] << "...";
        if (binSearchTree->addNode(ids1[i], strings1[i])) {
            cout << "added" << endl;
        }
        cout << "the height of the tree is " << binSearchTree->getHeight() << endl;
        cout << endl;
    }
    cout << endl;
    binSearchTree->displayTree();

    cout << "Testing getRootData() on non-empty tree" << endl;
    cout << "==============================================" << endl;
    if (binSearchTree->getRootData(&tempData)) {
        cout << "retrieved " << tempData.id << " " << tempData.information << endl;
    } else {
        cout << "NOT retrieved " << tempData.id << " " << tempData.information << endl;
    }
    cout << endl;

    /*
     *  testing contains randomly
     */
    cout << "Testing contains() randomly" << endl;
    cout << "==============================================" << endl;
    for (int i = 0; i < TESTDATA1; i++) {
        searchidx = random_range(0, TESTDATA1 - 1);
        binSearchTree->contains(ids1[searchidx]) ? cout << "contains " << ids1[searchidx] : cout << "does NOT contain " << ids1[searchidx];
        cout << endl;
    }
    tempid = random_range(1, 9);
    binSearchTree->contains(tempid) ? cout << "contains " << tempid : cout << "does NOT contain " << tempid;
    cout << endl;
    tempid = random_range(31, 39);
    binSearchTree->contains(tempid) ? cout << "contains " << tempid : cout << "does NOT contain " << tempid;
    cout << endl;
    tempid = random_range(1000, 9999);
    binSearchTree->contains(tempid) ? cout << "contains " << tempid : cout << "does NOT contain " << tempid;
    cout << endl;
    cout << "==============================================" << endl;
    cout << endl;

    /*
     *  testing get node
     */
    cout << "Testing getNode() randomly" << endl;
    cout << "==============================================" << endl;

    tempid = ids1[random_range(0, TESTDATA1 - 1)];
    if (binSearchTree->getNode(&tempData, tempid)) {
        cout << "retrieved: " << tempData.id << " " << tempData.information << endl;
    } else {
        cout << "NOT found: " << tempid << endl;
    }
    tempid = ids1[random_range(0, TESTDATA1 - 1)];
    if (binSearchTree->getNode(&tempData, tempid)) {
        cout << "retrieved: " << tempData.id << " " << tempData.information << endl;
    } else {
        cout << "NOT found: " << tempid << endl;
    }
    tempid = ids1[random_range(0, TESTDATA1 - 1)];
    if (binSearchTree->getNode(&tempData, tempid)) {
        cout << "retrieved: " << tempData.id << " " << tempData.information << endl;
    } else {
        cout << "NOT found: " << tempid << endl;
    }
    tempid = 1;
    if (binSearchTree->getNode(&tempData, tempid)) {
        cout << "retrieved: " << tempData.id << " " << tempData.information << endl;
    } else {
        cout << "NOT found: " << tempid << endl;
    }
    tempid = 1000;
    if (binSearchTree->getNode(&tempData, tempid)) {
        cout << "retrieved: " << tempData.id << " " << tempData.information << endl;
    } else {
        cout << "NOT found: " << tempid << endl;
    }
    cout << endl;

    /*
     *  testing removing nodes
     */
    cout << "Testing removeNode() randomly" << endl;
    cout << "==============================================" << endl;
    tempid = ids1[random_range(0, TESTDATA1 - 1)];
    cout << "removing " << tempid << "... ";
    binSearchTree->removeNode(tempid) ? cout << "removed" << endl : cout << "failed" << endl;
    binSearchTree->displayTree();

    binSearchTree->getRootData(&tempData);
    cout << "removing root " << tempData.id << "... ";
    binSearchTree->removeNode(tempData.id) ? cout << "removed" << endl : cout << "failed" << endl;
    binSearchTree->displayTree();

    tempid = ids1[random_range(0, TESTDATA1 - 1)];
    cout << "removing " << tempid << "... ";
    binSearchTree->removeNode(tempid) ? cout << "removed" << endl : cout << "failed" << endl;
    binSearchTree->displayTree();

    tempid = 35;
    cout << "removing " << tempid << "... ";
    binSearchTree->removeNode(tempid) ? cout << "removed" << endl : cout << "failed" << endl;

    cout << endl;
    binSearchTree->displayTree();
    cout << endl;

    cout << "adding 35... ";
    if (binSearchTree->addNode(35, "thirty five")) {
        cout << "added" << endl;
    }
    cout << endl;
    binSearchTree->displayTree();
    cout << endl;

    /*
     *  testing clearing tree
     *  and displaying it
     */
    cout << "Clearing tree... ";
    binSearchTree->clear();
    cout << "Cleared" << endl << endl;
    binSearchTree->displayTree();
    cout << endl;

    /*
     *  filling tree with poorly chosen test data and displaying it
     */
    cout << "Filling tree with poorly chosen data" << endl;
    cout << "==============================================" << endl;
    for (int i = 0; i < TESTDATA2; i++) {
        cout << "adding " << ids2[i] << "...";
        if (binSearchTree->addNode(ids2[i], strings2[i])) {
            cout << "added" << endl;
        }
        cout << "the height of the tree is " << binSearchTree->getHeight() << endl;
        cout << endl;
    }
    cout << endl;
    binSearchTree->displayTree();

    //delete tree and make sure the destructor works
    delete binSearchTree;

    cout << endl;
    return 0;
}

