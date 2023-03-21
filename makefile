blah: driver.cpp treenode.h tree.h tree.inl licorice.o
	g++ -o blah driver.cpp licorice.cpp


licorice.o: licorice.cpp licorice.h
	g++ -c licorice.cpp

clean:
	rm blah *.o
