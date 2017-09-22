package org.conscala
package ch2

import scala.collection._

object SynchronizedPool extends App {
  private val tasks = mutable.Queue[() => Unit]()

  object Worker extends Thread {
    setDaemon(true)

    def poll() = tasks.synchronized {
      while (tasks.isEmpty) tasks.wait()
      tasks.dequeue()
    }

    override def run(): Unit = while (true) {
      val task = poll()
      task()
    }
  }

  def async(body: => Unit): Unit = tasks.synchronized {
    tasks.enqueue(() => body)
    tasks.notify()
  }

  Worker.start()
  async { log("Hello, ") }
  async { log("world!") }
  Thread.sleep(100)
  }
