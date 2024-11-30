
# programming exercises

## write a malloc in C/C++/Rust

https://docs.google.com/document/d/1oXRP6smBt0WjC4rf346TvuSm6vdWkqfGDDU31Rblkc0/edit

## key value store binary data <--> struct design



## write your own user level thread package

https://github.com/brown-cs1690/handout/wiki/uthreads

in the industry this kind of software is typically provided by language runtimes

phread, java threads, C# threads, Go routines, green threads, multiprocessing

## 


# programming abstraction


```go

package main

import (
	"log"
	"time"
)

const NumWorkers = 10 // Define the number of workers

type Work struct {
	x, y, z int
}

func worker(in <-chan *Work, out chan<- *Work, done chan<- bool, id int) {
	for w := range in {
		log.Printf("Worker %d: Processing work: x=%d, y=%d\n", id, w.x, w.y)
		w.z = w.x * w.y
		time.Sleep(time.Duration(w.z) * time.Millisecond) // Simulate work
		log.Printf("Worker %d: Finished work: z=%d\n", id, w.z)
		out <- w
	}
	done <- true
	log.Printf("Worker %d: Exiting\n", id)
}

func sendLotsOfWork(in chan<- *Work) {
	for i := 0; i < 100; i++ {
		log.Printf("Sending work: %d\n", i)
		in <- &Work{x: i, y: i} // Sending work
	}
	close(in) // Close the channel to signal no more work
	log.Println("sendLotsOfWork: All work sent")
}

func receiveLotsOfResults(out <-chan *Work) {
	for w := range out {
		log.Printf("Received result: %d * %d = %d\n", w.x, w.y, w.z)
	}
	log.Println("receiveLotsOfResults: All results received")
}

func Run() {
	in, out := make(chan *Work), make(chan *Work)
	done := make(chan bool)

	for i := 0; i < NumWorkers; i++ {
		go worker(in, out, done, i)
	}

	go sendLotsOfWork(in)
	go receiveLotsOfResults(out)

	// Wait for all workers to finish
	for i := 0; i < NumWorkers; i++ {
		<-done
	}
	log.Println("Run: All workers have completed")
}

func main() {
	log.Println("Program started")
	Run()
	log.Println("Program finished")
}

```

```c
// segfault example

#include <stdio.h>

int main() {
    char *str = "hello world";
    str[0] = 'H'; // Attempt to modify a read-only memory
    printf("%s\n", str);
    return 0;
}

```

```
// writer reader

```

# c

# c++

# java

# python

# golang

# rust

# kotlin

# scala

# ocaml

# racket

# 