/*
 * GlobalTaskGroup.h
 *
 * Copyright (c) 2019 hikyuu.org
 *
 *  Created on: 2020-4-20
 *      Author: fasiondog
 */

#pragma
#ifndef HKU_GLOBAL_TASK_GROUP
#define HKU_GLOBAL_TASK_GROUP

#include "utilities/thread/ThreadPool.h"

#ifndef HKU_API
#define HKU_API
#endif

namespace hku {

/**
 * 获取全局线程池任务组
 * @note 请使用 future 获取任务返回
 */
HKU_API ThreadPool* getGlobalTaskGroup();

template <typename ResultType>
using task_handle = std::future<ResultType>;

/**
 * 向全局任务池中增加任务
 */
template <typename FunctionType>
task_handle<typename std::result_of<FunctionType()>::type> addTask(FunctionType f) {
    return getGlobalTaskGroup()->submit(f);
}

/*
 * 内部函数，初始化全局任务组
 */
void initThreadPool();

/* 内部函数，初始化全局任务组 */
void releaseThreadPool();

} /* namespace hku */

#endif /* HKU_GLOBAL_TASK_GROUP */
