#include <gtest/gtest.h>
#include "linkedList.cpp"  // Ensure that linkedList.cpp includes the template definition as shown previously.

// Testing the linked list with integer data
TEST(DoublyLinkedListTest, IntegerNodeTest) {
  DoublyLinkedList<int> list;
  int* data1 = new int(10);
  int* data2 = new int(20);
  int* data3 = new int(30);

  list.addNode(data1);
  list.addNode(data2);
  list.addNode(data3);

  EXPECT_EQ(*(list.head->data), 10);
  EXPECT_EQ(*(list.tail->data), 30);

  int removeValue = 20;
  list.removeNode(&removeValue);
  EXPECT_EQ(*(list.head->next->data), 30);

  list.removeNode(data1);
  EXPECT_EQ(*(list.head->data), 30);

  list.removeNode(data3);
  EXPECT_EQ(list.head, nullptr);
}

// Testing the linked list with string data
TEST(DoublyLinkedListTest, StringNodeTest) {
  DoublyLinkedList<std::string> list;
  std::string* data1 = new std::string("Hello");
  std::string* data2 = new std::string("World");
  std::string* data3 = new std::string("Test");

  list.addNode(data1);
  list.addNode(data2);
  list.addNode(data3);

  EXPECT_EQ(*(list.head->data), "Hello");
  EXPECT_EQ(*(list.tail->data), "Test");

  std::string removeValue = "World";
  list.removeNode(&removeValue);
  EXPECT_EQ(*(list.head->next->data), "Test");

  list.removeNode(data1);
  EXPECT_EQ(*(list.head->data), "Test");

  list.removeNode(data3);
  EXPECT_EQ(list.head, nullptr);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
