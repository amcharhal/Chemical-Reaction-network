#include "generategraph.h"
#include "readdata.h"
#include "node.h"
#include "reaction.h"
#include "molecule.h"
#include <gtest/gtest.h>
#include <memory>

//Create a graph object and data files

Data dataList = Data("datatest.txt");
data = dataList.data;

Graph myGraph = Graph(dataList);

TEST(ReadData, datalentgh) { 

    int data_size=  dataList.data->size();
    ASSERT_EQ(data_size, 2);
}
TEST(GraphGenarate, reaction_size) { 
    size_t reaction_size = myGraph.reactionElements.size();
    ASSERT_EQ(reaction_size, 2);
}
TEST(GraphGenarate, molecules_size) { 
    size_t molecules_size = myGraph.moleculeElements.size();
    ASSERT_EQ(molecules_size, 4);
}
TEST(GraphGenarate, molecules) { 
    string molecules;
    string expectMolecules{"ABCD"};
    for(Molecule mol : myGraph.moleculeElements)
        molecules += mol.nameNode;
    EXPECT_STREQ(expectMolecules,molecules);
}

TEST(GraphGenarate, reactions) { 
    string reactions;
    string expectreactions{"R1R2"};
    for(Reaction rec : myGraph.reactionElements)
        reactions += rec.nameNode;
    EXPECT_STREQ(expectreactions,reactions);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
