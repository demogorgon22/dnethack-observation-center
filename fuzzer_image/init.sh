#!/bin/sh
sysctl -w kernel.core_pattern=/tmp/cores/core-%e.%p.%h.%t
cd /app/dnh/dnethackdir
/app/dnh/dnethackdir/dnethack -D -u `hostname` > /dev/null
sleep 10
CORES_DIR="/cores/dnethack-$(git rev-parse HEAD)"
mkdir $CORES_DIR
cp /tmp/cores/* $CORES_DIR
if [ -e /cores/dnh/dnethackdir/dnethack ]
then
	echo "DNH install exists, checking hash"
	ourHash=$(md5sum /app/dnh/dnethackdir/dnethack | cut -f 1 -d ' ')
	theirHash=$(md5sum $CORES_DIR/dnh/dnethackdir/dnethack | cut -f 1 -d ' ')
	echo "$ourHash, $theirHash"
	if [[ "$ourHash" == "$theirHash" ]]
	then
		echo "DNH install in date, exiting"
	else
		echo "DNH install out of date, updating"
		rm -rf $CORES_DIR/dnh
		cp -r /app/dnh $CORES_DIR/dnh
	fi
else
	echo "DNH install nonexistent, updating"
	rm -rf $CORES_DIR/dnh
	cp -r /app/dnh $CORES_DIR/dnh
fi
