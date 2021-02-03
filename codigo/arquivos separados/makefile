main: main.o aux_funcs.o studentlist.o collegestack.o proposalstack.o students.o college.o
	gcc main.o aux_funcs.o studentlist.o collegestack.o proposalstack.o students.o college.o -o main

aux_funcs.o: src/aux_funcs.c include/aux_funcs.h
	gcc -c src/aux_funcs.c

studentlist.o: src/studentlist.c include/studentlist.h
	gcc -c src/studentlist.c

collegestack.o: src/collegestack.c include/collegestack.h
	gcc -c src/collegestack.c

proposalstack.o: src/proposalstack.c include/proposalstack.h
	gcc -c src/proposalstack.c

students.o: src/students.c include/students.h
	gcc -c src/students.c

college.o: src/college.c include/college.h
	gcc -c src/college.c

main.o: main.c
	gcc -c main.c

.PHONY: clean

clean:
	rm main.o aux_funcs.o studentlist.o collegestack.o proposalstack.o students.o college.o
