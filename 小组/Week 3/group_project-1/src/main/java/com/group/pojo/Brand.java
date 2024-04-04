package com.group.pojo;

/**
 * @author 20127
 */
public class Brand {
    private String brand_Name;
    private String company_Name;
    private int ordered;

    private int status;

    public String getBrand_Name() {
        return brand_Name;
    }

    public void setBrand_Name(String brand_Name) {
        this.brand_Name = brand_Name;
    }

    public String getCompany_Name() {
        return company_Name;
    }

    public void setCompany_Name(String company_Name) {
        this.company_Name = company_Name;
    }

    public int getOrdered() {
        return ordered;
    }

    public void setOrdered(int ordered) {
        this.ordered = ordered;
    }

    public int getStatus() {
        return status;
    }

    public void setStatus(int status) {
        this.status = status;
    }

    @Override
    public String toString() {
        return "Brand{" +
                "brand_Name='" + brand_Name + '\'' +
                ", company_Name='" + company_Name + '\'' +
                ", ordered=" + ordered +
                ", status=" + status +
                '}';
    }
}
