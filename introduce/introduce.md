## MPI入门

MPI_Init()

MPI_Comm_size()

MPI_Comm_rank()

MPI_FInalize()

getpid()

getppid()

MPI_Send()

MPI_Recv()

MPI_Sendrecv()

MPI_Sendrecv_replace()

MPI_Status()

MPI_Isend()

MPI_Irecv()

MPI_Request



MPI_Wait()

MPI_Waitany()

MPI_Waitsome()

MPI_Waitall()

MPI_Test()

MPI_Testany()

MPI_Testsome()

MPI_Testall()



### 消息查询

MPI_Probe()

MPI_Iprobe()



### 持久（重复）非阻塞通信

MPI_Send_init()

MPI_Recv_init()

MPI_Start()

MPI_Startall()

（需要 MPI_Wait\*() 或 MPI_Test\*() 配合）





** notice: 不要迷信MPI，侧重点可能不同。 **