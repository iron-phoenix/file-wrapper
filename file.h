#ifndef __FILE_H__
#define __FILE_H__

struct File{
    enum open_mode {Read, Write};

    File();
    explicit File(std::string const &fname, open_mode mode = Read);
    ~File();

    void open(std::string const &fname, open_mode mode = Read);
    void close();

    open_mode mode() const;

    bool opened() const;
    bool eof() const;
    bool error const;

    size_t write(char const &buf, size_t size);
    size_t write(std::string const &str);
    size_t write(char value);
    size_t write(long value);
    size_t write(unsigned long value);
    size_t write(double value);

    size_t read(char *buf, size_t size);
    size_t read(std::string &word);
    size_t read(char &value);
    size_t read(long &value);
    size_t read(unsigned long &value);
    size_t read(double &value);
    size_t readline(std::string &line);

private:
    FILE *in;
    bool opened;

    File(File const &);
    void operator=(File const &);
}

#endif
