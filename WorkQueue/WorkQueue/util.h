#pragma once
class NoneCopyable {
public:
	NoneCopyable() {};
	NoneCopyable(const NoneCopyable&) = delete;
	NoneCopyable& operator=(const NoneCopyable&) = delete;
};