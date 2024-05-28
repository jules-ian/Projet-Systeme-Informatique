ps -ef | grep vivado | awk '{print $2}' | xargs kill -9
