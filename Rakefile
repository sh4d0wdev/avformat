require "bundler/gem_tasks"
require "rspec/core/rake_task"
require "rake/extensiontask"

GEMSPEC = Gem::Specification.load('avformat.gemspec')

RSpec::Core::RakeTask.new(:spec)

Rake::ExtensionTask.new("rubyavformat", GEMSPEC) do |ext|
    ext.ext_dir = 'ext'
    ext.source_pattern = '*.{h,c}'
end

desc "Build avformat and test"
task :default => [:compile, :spec]


