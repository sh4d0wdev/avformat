# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'avformat/version'

Gem::Specification.new do |spec|
  spec.name          = "avformat"
  spec.version       = AVFormat::VERSION
  spec.authors       = ["Nik Kotykhov"]
  spec.email         = ["nikolay.kotykhov@gmail.com"]

  spec.summary       = %q{Write a short summary, because Rubygems requires one.}
  spec.description   = %q{Write a longer description or delete this line.}
  spec.homepage      = "http://google.com"
  spec.license       = "MIT"


  spec.files         = `git ls-files -z`.split("\x0").reject { |f| f.match(%r{^(test|spec|features)/}) }
  spec.bindir        = "exe"
  spec.executables   = spec.files.grep(%r{^exe/}) { |f| File.basename(f) }
  spec.extensions     = ["ext/extconf.rb"]

  spec.add_development_dependency "rake-compiler"
  spec.add_development_dependency "bundler", "~> 1.7"
  spec.add_development_dependency "rake", "~> 10.0"
  spec.add_development_dependency "rspec"
end
