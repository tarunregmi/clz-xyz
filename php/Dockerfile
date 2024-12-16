# Official PHP image with Apache as the base image
FROM php:apache

# For MySQL database
RUN docker-php-ext-install mysqli

# Update and install system dependencies
RUN apt-get update
RUN apt-get install -y git zip unzip

# Install Composer globally
RUN curl -sS https://getcomposer.org/installer | php -- --install-dir=/usr/local/bin --filename=composer

# Set file permissions to ensure Apache can read the files
RUN chown -R www-data:www-data /var/www/html \
  && chmod -R 755 /var/www/html

# Expose port 80 to be able to access the application
EXPOSE 80
