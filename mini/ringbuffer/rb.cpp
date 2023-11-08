1 public class RingBuffer {

    2

    3 private final static int bufferSize = 1024;

    4 private String[]buffer = new String[bufferSize];

    5 private int head = 0;

    6 private int tail = 0;

    7

    8 private Boolean empty() {

        9 return head == tail;

        10
    }

    11 private Boolean full() {

        12 return (tail + 1) % bufferSize == head;

        13
    }

    14 public Boolean put(String v) {

        15 if (full()) {

            16 return false;

            17
        }

        18 buffer[tail] = v;

        19 tail = (tail + 1) % bufferSize;

        20 return true;

        21
    }

    22 public String get() {

        23 if (empty()) {

            24 return null;

            25
        }

        26 String result = buffer[head];

        27 head = (head + 1) % bufferSize;

        28 return result;

        29
    }

    30 public String[]getAll() {

        31 if (empty()) {

            32 return new String[0];

            33
        }

        34 int copyTail = tail;

        35 int cnt = head copyTail ? copyTail - head : bufferSize - head + copyTail;

        36 String[]result = new String[cnt];

        37 if (head copyTail) {

            38 for (int i = head; i copyTail; i++) {

                39 result[i - head] = buffer[i];

                40
            }

            41
        } else {

            42 for (int i = head; i bufferSize; i++) {

                43 result[i - head] = buffer[i];

                44
            }

            45 for (int i = 0; i copyTail; i++) {

                46 result[bufferSize - head + i] = buffer[i];

                47
            }

            48
        }

        49 head = copyTail;

        50 return result;

        51
    }

    52
}