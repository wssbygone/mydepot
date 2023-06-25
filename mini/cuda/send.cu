#include "flowtranfer.hpp"
#include <thread>
#include <chrono>
#include <unistd.h>
#include <iostream>
#include <sys/time.h>

#define DSIZE 128

void handletobuffer(cudaIpcMemHandle_t my_handle, char *buf,size_t buf_size)
{
    memset(buf, 0, sizeof(my_handle)+1);
    memcpy(buf, (char *)(&my_handle), sizeof(my_handle));
}

int main(int argc ,char **argv)
{
	char buf[64];
    char handlebuf[128];

    char  *data;
    struct timeval tm;
    cudaIpcMemHandle_t my_handle;
 	FlowSend *pptr = new FlowSend("0.0.0.0","24014");

	while(1){
        cudaMalloc(&data, DSIZE*sizeof(char));
        cudaMemset(data, 0, DSIZE*sizeof(char));
        cudaIpcGetMemHandle(&my_handle, data);

        gettimeofday(&tm,NULL);
        sprintf(buf,"%ld: %ld \n",tm.tv_sec,tm.tv_usec);
        printf("%s \n",buf);
        cudaMemcpy(data, buf, 64*sizeof(char), cudaMemcpyHostToDevice);
        handletobuffer(my_handle,handlebuf,sizeof(handlebuf));

 		pptr->send("camera0",static_cast<char*>(handlebuf),sizeof(handlebuf));
        sleep(1);
	}
}

