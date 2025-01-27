#include "model.h"

Model::Model(const std::string &binaryFileName)
{
    this->binaryFileName = binaryFileName;
}

void Model::writeBinaryFile(const std::vector<Employee>& employees) const
{
    std::fstream fout(binaryFileName.c_str(), std::ios::binary | std::ios::out);
    fout.seekp(0);
    for (std::size_t i = 0; i < employees.size(); ++i)
    {
        fout.write(reinterpret_cast<const char *>(&employees[i]), sizeof(Employee));
    }
}

Employee Model::readRecord(const std::size_t &recordId) const
{
    std::fstream f(binaryFileName.c_str(), std::ios::binary | std::ios::in);
    Employee employee;
    f.seekg(singleOffset * recordId);
    f.read(reinterpret_cast<char *>(&employee), sizeof(Employee));
    return employee;
}

void Model::writeRecord(const std::size_t &recordId, const Employee &newRecord) const
{
    std::fstream f(binaryFileName.c_str(), std::ios::binary | std::ios::in | std::ios::out);
    f.seekp(recordId * singleOffset);
    f.write(reinterpret_cast<const char*>(&newRecord), sizeof(Employee));
}
