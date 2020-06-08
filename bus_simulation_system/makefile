all: TransitSim tests

check-style:
	cd src; make check-style

check-style-cse:
	cd src; make check-style-cse

TransitSim:
	cd src; make -j

tests:
	cd tests; make -j

clean:
	rm -rf build

clobber: clean
	cd ../external/googletest; make clean